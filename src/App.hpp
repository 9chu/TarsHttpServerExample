#pragma once
#include <servant/Application.h>

class App :
    public tars::Application
{
public:
    static App& GetInstance();

public:
    virtual ~App() = default;

public:
    /**
     * @brief 应用程序初始化函数
     */
    virtual void initialize()override;

    /**
     * @brief 应用程序销毁函数
     */
    virtual void destroyApp()override;
};
