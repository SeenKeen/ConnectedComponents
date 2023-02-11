#include "grid_window.h"

#include "color_grid.h"
#include "ns_view_window.h"

#import <Cocoa/Cocoa.h>

GridWindow::GridWindow(std::unique_ptr<ColorGrid> grid) : grid_(std::move(grid)) {
    NSWindow *myWindow;      // typed pointer to NSWindow object
    NSView   *myView;        // typed pointer to NSView object
    NSRect    graphicsRect;  // contains an origin, width, height

    // initialize the rectangle variable
    graphicsRect = NSMakeRect(100.0, 350.0, 800.0, 800.0);

    myWindow = [[NSWindow alloc]              // create the window
               initWithContentRect: graphicsRect
                         styleMask:NSTitledWindowMask 
                                  |NSClosableWindowMask 
                                  |NSMiniaturizableWindowMask
                           backing:NSBackingStoreBuffered
                             defer:NO ];

    [myWindow setTitle:@"Tiny Application Window"];


    //create amd initialize the DemoView instance
    myView = [[[NSViewWindow alloc] initWithGrid:  grid_.get()
                                    Frame: graphicsRect] 
              autorelease];

    //myView = [[[DemoView alloc] initWithFrame: graphicsRect] autorelease];

    [myWindow setContentView:myView ];    // set window's view

    [myWindow setDelegate:(id)myView ];   // set window's delegate
    [myWindow makeKeyAndOrderFront: nil]; // display window
}

