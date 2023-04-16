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


    auto builder = Actor::Build("test1", EActorType::Player);
    builder->add_child("child01", EActorType::Object)
        .add_child("child02", EActorType::Object);

    return 0;
}
