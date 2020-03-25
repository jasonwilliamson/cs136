//
//  roots.h
//  A3P5
//
//  Created by Jason Williamson on 2015-05-30.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#ifndef __A3P5__roots__
#define __A3P5__roots__

#include <stdio.h>
#include <stdbool.h>

float f(float a, float b, float c, float x);
float avg_of_2(float p, float q);
bool close_to_zero(float y);

float find_root(float a, float b, float c, float p, float q);

#endif /* defined(__A3P5__roots__) */
