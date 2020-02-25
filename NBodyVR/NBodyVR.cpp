#include <cstdio>
#include <GL/_Window.h>
#include <GL/_NBody.h>
#include <_Math.h>
#include <_Time.h>


int main()
{
	OpenGL::OpenGLInit(4, 5);
	Window::Window::Data winPara
	{
		"NBodyVR",
		{
			{640,360},
			true,false
		}
	};
	Window::WindowManager wm(winPara);
	OpenGL::VR::NBodyVR nBody(20);
	wm.init(0, &nBody);
	glfwSwapInterval(0);
	FPS fps;
	fps.refresh();

	while (!wm.close())
	{
		wm.pullEvents();
		wm.render();
		wm.swapBuffers();
		//fps.refresh();
		//fps.printFPSAndFrameTime(2, 3);
		//wm.windows[0].data.setTitle(fps.str);
	}
	vr::VR_Shutdown();
	return 1;
}