
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
	XSelectInput( display, testWindow, KeyPressMask|KeyReleaseMask );
	XMapWindow( display, testWindow );

	// handling the events for the window
	printf("Entering event processing\n");
	XEvent event;
	while( true )
	{
		XNextEvent( display, &event );

		if( KeyRelease == event.type )
		{
			XKeyEvent* keyEvent = &event.xkey;
			printf("%i\n", keyEvent->keycode );
		}
	}

	return 0;
}

