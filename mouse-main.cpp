
// header files
#include <X11/Xlib.h>
#include <stdio.h>

int main( int argc, char** argv )
{
	Display* display =  XOpenDisplay( NULL );
	if( !display )
		return 0;

	Window rootWindow = XDefaultRootWindow( display );

	// creating a window which will test mouse featres
	Window testWindow = XCreateSimpleWindow( display, rootWindow, 10, 10, 300, 150, 1, 0, 0 );
	XSelectInput( display, testWindow, ButtonPressMask|ButtonReleaseMask );
	XMapWindow( display, testWindow );

	// handling the events for the window
	printf("Entering event processing\n");
	XEvent event;
	while( true )
	{
		XNextEvent( display, &event );

		if( ButtonRelease == event.type )
		{
			XButtonEvent* buttonEvent = &event.xbutton;

			switch( buttonEvent->button )
			{
			case Button1:
				printf("button1\n");
				break;

			case Button2:
				printf("button2\n");
				break;

			case Button3:
				printf("button3\n");
				break;

			case Button4:
				printf("button4\n");
				break;

			case Button5:
				printf("button5\n");
				break;

			default:
				break;
			}
		}
	}

	return 0;
}

