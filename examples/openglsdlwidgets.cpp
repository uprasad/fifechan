/**
 * This is an example that shows of the widgets present in
 * Guichan. The example uses the OpenGL back end and the 
 * SDL back end.
 */

#include <fifechan.hpp>
#include <iostream>

// Here we store a global Gui object.  We make it global
// so it's easily accessable. Of course, global variables
// should normally be avioded when it comes to OOP, but
// this examples is not an example that shows how to make a 
// good and clean C++ application but merely an example
// that shows how to use Guichan.
namespace globals
{
    fcn::Gui* gui;
}

// Include code to set up an OpenGL and SDL application with Guichan.
// The openglsdl.hpp file is responsible for creating and deleting
// the global Gui object.
#include "openglsdl.hpp"
// Include code to set up a Guichan GUI with all the widgets
// of Guichan. The code populates the global Gui object.
#include "widgets.hpp"

int main(int argc, char **argv)
{
    try
    {
        openglsdl::init();
        widgets::init();
        openglsdl::run();
        widgets::halt();
        openglsdl::halt();
    }
    // Catch all Guichan exceptions.
    catch (fcn::Exception e)
    {
        std::cerr << e.getMessage() << std::endl;
        return 1;
    }
    // Catch all Std exceptions.
    catch (std::exception e)
    {
        std::cerr << "Std exception: " << e.what() << std::endl;
        return 1;
    }
    // Catch all unknown exceptions.
    catch (...)
    {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }

    return 0;
}
