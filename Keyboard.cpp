#include <Windows.h>
#include "keyboard.h"

HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);  // handle to read console

DWORD Events = 0;     // Event count
DWORD EventsRead = 0; // Events read from console

unsigned short KeyPressed() {

	unsigned short resultKey = 0;

	GetNumberOfConsoleInputEvents(rhnd, &Events);

	if (Events != 0) { // if something happened we will handle the events we want

					   // create event buffer the size of how many Events
		INPUT_RECORD *eventBuffer = new INPUT_RECORD[Events];

		// fills the event buffer with the events and saves count in EventsRead
		ReadConsoleInput(rhnd, eventBuffer, Events, &EventsRead);

		// loop through the event buffer using the saved count
		for (DWORD i = 0; i < EventsRead; ++i) {

			// check if event[i] is a key event && if so is a press not a release
			if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown) {
				resultKey = eventBuffer[i].Event.KeyEvent.wVirtualKeyCode;
			}

		} // end EventsRead loop
		delete[] eventBuffer;

	}
	return resultKey;
}