#include "macos_window.h"

#ifdef Q_OS_MAC

#import <Cocoa/Cocoa.h>

void applyMacDarkWindow(WId wid) {
	if (!wid) {
		return;
	}

	NSView* view = (__bridge NSView*)(void*)wid;
	NSWindow* window = view.window;
	if (!window) {
		return;
	}

	if (@available(macOS 10.14, *)) {
		window.appearance = [NSAppearance appearanceNamed:NSAppearanceNameDarkAqua];
	}
	window.backgroundColor = [NSColor colorWithCalibratedRed:0x1e / 255.0
	                                                     green:0x1e / 255.0
	                                                      blue:0x1e / 255.0
	                                                     alpha:1.0];
}

#endif
