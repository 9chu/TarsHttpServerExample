#include "App.hpp"
#include "HttpServant.hpp"

using namespace std;
using namespace tars;

App& App::GetInstance()
{
    static App s_stInstance;
    return s_stInstance;
}

void App::initialize()
{
    auto servantName(ServerConfig::Application + "." + ServerConfig::ServerName + ".HttpServantObj");

    // 注册Servant，并设置专有协议（非TARS协议）
    addServant<HttpServant>(servantName);
    addServantProtocol(servantName, HttpServant::HttpProtocolSplitter);
}

void App::destroyApp()
{
}
