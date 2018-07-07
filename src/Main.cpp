#include "App.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        auto& app = App::GetInstance();
        app.main(argc, argv);
        app.waitForShutdown();
    }
    catch (std::exception& ex)
    {
        cerr << "Program exit with std::exception: " << ex.what() << std::endl;
        return -1;
    }
    catch (...)
    {
        cerr << "Program exit with unknown exception" << std::endl;
        return -1;
    }
    return 0;
}
