#include "HttpServant.hpp"

using namespace std;
using namespace tars;

int HttpServant::HttpProtocolSplitter(std::string& in, std::string& out)noexcept
{
    try
    {
        bool b = TC_HttpRequest::checkRequest(in.c_str(), in.length());
        if (b)
        {
            out = std::move(in);
            in.clear();
            return TC_EpollServer::PACKET_FULL;
        }
        else
            return TC_EpollServer::PACKET_LESS;
    }
    catch (std::exception& ex)
    {
        return TC_EpollServer::PACKET_ERR;
    }
}

void HttpServant::initialize()
{
}

void HttpServant::destroy()
{
}

int HttpServant::doRequest(TarsCurrentPtr current, std::vector<char>& buffer)
{
    TC_HttpRequest request;
    string requestBuffer;
    requestBuffer.assign(current->getRequestBuffer().data(), current->getRequestBuffer().size());
    request.decode(requestBuffer);

    TC_HttpResponse response;
    string responseBuffer = "Hello world!";
    response.setResponse(responseBuffer.data(), responseBuffer.length());
    response.encode(buffer);
    return 0;
}
