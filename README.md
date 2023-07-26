
ECS - Entity Component System
-

This is just simple ECS that i make for fun only. If you want full-fledged ECS then just use [EnTT](https://github.com/skypjack/entt)

Prerequisities 
- 
1. [Premake](https://premake.github.io/)

How to use 
-
1. Simply include "include/" into your project.
2. take a look at example folder to understand how to use it.

List of functionality
-

1. ```getList<T>()``` - return ```std::vector<T>``` that store all your component. <br>example : ```auto transforms = getList<transform>();```
2. Entity - container class that contain reference to all it's component, <br>example : ```Entity GameObject;```
    - ```add<T>``` - Add component T to Entity. Return newly created T&. <br>example : ```GameObject.add<Transform>({2, 3});```
    - ```get<T>``` - if exist, return reference to T (dont store it as reference, it could deallocate) <br>example: ```GameObject.get<Transform>().x = 10```
    - ```getComponent<T>``` - return ```Component<T>```.
3. ```Component<T>``` - struct that contain index and type of T. You can store it to reference component. <br>example : ```Component<Transform> transform = GameObject.getComponent<Transform>();```
    - ```get()``` - if exist, return reference to T, same as ```get<T>``` dont store as reference. <br>example : ```transform.get().y = 99;```
    - ```getOther<U>()``` - if exist, return reference to component U that belong to the same entity. <br>example : ```transform.getOther<Color>().set("Green");```



C++ template by [muhhae](github.com/muhhae)
-
Build this project using [premake](https://premake.github.io/)
-
