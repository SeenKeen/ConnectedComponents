#include "ns_view_window.h"
#include "util.h"

@implementation NSViewWindow        // implementation of DemoView class

- (id)initWithGrid:(ColorGrid*)grid Frame:(NSRect)rect {
    grid_ = grid;
    return [super initWithFrame:rect];
}

- (void)drawRect:(NSRect)rect   // instance method implementation
{
    if (grid_) {
        NSLog(@"grid_ is not null");
    } else {
        NSLog(@"grid_ is null");
    }

    int n = grid_->Rows();                 // number of sides of the polygon
    int m = grid_->Columns();

    // get the size of the application's window and view objects
    float width  = [self bounds].size.width;
    float height = [self bounds].size.height;

    [[NSColor whiteColor] set];   // set the drawing color to white
    NSRectFill([self bounds]);    // fill the view with white

    // the following statements trace two polygons with n sides
    // and connect all of the vertices with lines

    [[NSColor blackColor] set];   // set the drawing color to black

    float block_h = height/n;
    float block_w = width/m;

    @autoreleasepool {
        for (int i = 0; i < n; i++) {        // draw the fancy pattern
            for (int j = 0; j < m; j++) {
                auto* color = ToNsColor(grid_->Get(i, j));
                [color set];
                NSRect rect;
                rect.origin.x = block_w * j;
                rect.origin.y = block_h * i;
                rect.size.width = block_w;
                rect.size.height = block_h;
                NSRectFill(rect);
            }
        }
    }

} // end of drawRect: override method

/* windowWillClose: is a delegate method that gets invoked when
 * the on-screen window is about to close (user clicked close box).
 * In this case, we force the entire application to terminate.
 */

-(void)windowWillClose:(NSNotification *)notification
{
    [NSApp terminate:self];
}
@end  // end of DemoView implementation