#pragma once
#include <servant/Application.h>

class HttpServant :
    public tars::Servant
{
public:
    /**
     * @brief HTTP协议分包函数
     *
     * 用于将TCP数据流切割成单一HTTP请求。
     */
    static int HttpProtocolSplitter(std::string& in, std::string& out)noexcept;

public:
    virtual ~HttpServant() = default;

public:
    /**
     * @brief 服务对象初始化函数
     */
    virtual void initialize()override;

    /**
     * @brief 服务对象销毁函数
     */
    virtual void destroy()override;

    /**
     * @brief 消息处理函数
     * @param current 请求源端
     * @param buffer 数据缓冲区
     * @return 处理结果
     */
    virtual int doRequest(tars::TarsCurrentPtr current, std::vector<char>& buffer)override;
};
