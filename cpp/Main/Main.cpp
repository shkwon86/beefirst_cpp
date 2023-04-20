#include "Main.h"
#include "../Actor/ActorSpecification.h"
#include "../Actor/Builder.h"

// 3D vector class
class Vector3
{
public:
	double x, y, z;

	Vector3(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) {}

	Vector3 operator+(const Vector3& v) const
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 operator-(const Vector3& v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 operator*(double s) const
	{
		return Vector3(x * s, y * s, z * s);
	}
};

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

	const double GRAVITY = 9.8; // 중력가속도
	const int FPS = 60; // 초당 프레임수

	Vector3 pos(0.0, 0.0, 0.0); // 시작 위치
	Vector3 vel(10.0, 20.0, 30.0); // 초기 속도
	double time = 0.0; // 시작 시간

	// 매 프레임마다 위치 계산하고 출력하기
	for (int frame = 0; frame < 60; frame++)
	{
		// 중력 가속도에 따른 변화량 계산
		Vector3 gravity(0.0, -GRAVITY, 0.0);
		Vector3 deltaPos = vel * (1.0 / FPS);
		Vector3 deltaVel = gravity * (1.0 / FPS);

		// 새로운 위치와 속도 계산
		pos = pos + deltaPos;
		vel = vel + deltaVel;
		time += 1.0 / FPS;

		// 현재 시간, 위치, 속도 출력
		std::cout << "Time: " << time << ", Position: (" << pos.x << ", " << pos.y << ", " << pos.z << "), Velocity: (" << vel.x << ", " << vel.y << ", " << vel.z << ")" << std::endl;
	}

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



