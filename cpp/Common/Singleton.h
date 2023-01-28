#pragma once

template<typename T>
class Singleton
{
private:
    static T* instance;

public:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static T* GetInstance()
    {
        if (instance == nullptr)
            instance = new T();

        return instance;
    }
};

template<typename T> T* Singleton<T>::instance = nullptr;
