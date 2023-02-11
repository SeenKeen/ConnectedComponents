#pragma once

#import <Cocoa/Cocoa.h>

#include "color_grid.h"

@interface NSViewWindow : NSView
{
ColorGrid *grid_;
}

- (void)drawRect:(NSRect)rect;
- (id)initWithGrid:(ColorGrid*)grid Frame:(NSRect)rect;
@end
