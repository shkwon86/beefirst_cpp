#include "Main.h"
#include "../Actor/ActorSpecification.h"
#include "../Actor/Builder.h"

int main()
{
    ExamLambda lambda;
    lambda.Sort();

    /// <summary>
    /// Filter Test
    /// </summary>
    /// <returns></returns>
    Actor* park = new Actor{ "park", EActorType::Player };
    Actor* kim = new Actor{ "kim", EActorType::Player };
    Actor* ork = new Actor{ "ork", EActorType::Monster };

    std::vector<Actor*> actors{ park, kim, ork };

    ActorFilter filter;
    ActorNameSpecification spec{ "park" };
    ActorTypeSpecification typeSpec{ EActorType::Player };

    auto andSpec = ActorNameSpecification("park") && ActorTypeSpecification(EActorType::Player);

    auto filterActors = filter.filter(actors, spec);

    for (auto collectActor : filterActors)
    {
        if (collectActor)
        {
            std::cout << "Collect Name: " << collectActor->GetName() << std::endl;
        }
    }

    for (auto actor : actors)
    {
        if (actor)
        {
            delete actor;
            actor = nullptr;
        }
    }

    actors.clear();


    /// <summary>
    /// Tag Test
    /// </summary>
    /// <returns></returns>
    std::cout <<
        P
        {
            IMG {"http://naver.com"},
            IMG {"http://google.com"}
        }
    << std::endl;


    //auto builder = Actor::Build("test1", EActorType::Player);
    //builder->add_child("child01", EActorType::Object)
    //    .add_child("child02", EActorType::Object);


	const double g = 9.8; // 중력가속도
	const double h = 10.0; // 최대 높이
	const int fps = 60; // 초당 60프레임

	double time = sqrt(2 * h / g); // 최대 높이에 도달하는 시간
	double velocity = g * time / fps; // 초당 60프레임으로 계산된 속도

	std::cout << "Initial velocity: " << velocity << std::endl;
    std::cout << "total time: " << time << std::endl;

    std::cout << "velocity sec :" << g * time << std::endl;

    return 0;
}


///////////////////////////////////////////////////////
// 콤보 시스템



///////////////////////////////////////////////////////
// 무브먼트 개선 아이디어
/**
 * Air 상태일 때 중력 + Velocity 을 항시 업데이트
 * - Velocity 유지는 공중방향 조종 시에는 적용하지 않는다.?
 * 
 * 적용안되는 조건
 * - 랜딩되면 업데이트 하지 않는다. (Air일 때만 이므로 자동)
 * - 시퀀스에서 중력적용을 끈다.
 * - 시퀀스에서 벨로시티 유지 기능을 끈다.
 * 
 * 추가적용
 * - 시퀀스에서 추가적인 중력을 설정한다.
 * 
 * 예시
 * - 점프시작 시 Air 상태 (중력적용)
 * - Veolcity 유지기능을 켠다.
 * - 기획자는 최고높이를 설정하면 내부적으로 시퀀스 완료 시점에서 최고위치에 도달하도록
 *   초기속도를 역산하여 적용한다.
 *
 * 
 */



