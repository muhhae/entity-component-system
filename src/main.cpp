#include <iostream>

#include "Entity/Entity.hpp"
#include "Component/Transform.hpp"

void checkEntity()
{
    nty::Entity gameObject;
    gameObject.get<Transform>() = {9, 7, 8};
    gameObject.get<Transform>().x = 10;

    nty::Component<Transform> transform = gameObject.getComponent<Transform>();

    transform.get().x = 100;

    std::cout << gameObject.get<Transform>().x << " " << gameObject.get<Transform>().y << " " << gameObject.get<Transform>().z << std::endl;
}

int main()
{
    checkEntity();

    return 0;
}