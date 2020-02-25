#include <cstdio>
#include <GL/_Window.h>
#define _CUDA
#include <GL/_NBody.h>
#include <_Math.h>
#include <_Time.h>


int main()
{
	OpenGL::OpenGLInit init(4, 5);
	Window::Window::Data winParameters
	{
		"NBodyCUDA",
		{
			{800,800},
			true,false
		}
	};
	Window::WindowManager wm(winParameters);
	CUDA::OpenGLDeviceInfo intro;
	intro.printInfo();
	OpenGL::VR::NBodyCUDAVR nBody(60 * 1, false);
	::printf("Num particles: %d\n", nBody.particles.particles.length);

	wm.init(0, &nBody);
	init.printRenderer();
	glfwSwapInterval(0);
	//nBody.experiment();
	FPS fps;
	fps.refresh();
	while (!wm.close())
	{
		wm.pullEvents();
		wm.render();
		wm.swapBuffers();
		fps.refresh();
		::printf("\r%.2lf    ", fps.fps);
		//fps.printFPS(1);
	}
	vr::VR_Shutdown();
	return 0;
}