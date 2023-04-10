# OpenGL-Win32-triangle

this is the msvc 2019 default win32 c++ app framework with comments removed, a timer added to call WM_PAINT for animation, and OpenGL instructions to clear the screen and draw a triangle with a moving point during WM_PAINT.

the only dependencies are:


#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>

#pragma comment(lib, "opengl32.lib")



i'm new to actually using OpenGL so i don't know if i'm imparting any poor methods because it's taken so long (15 years+) to determine an effective yet minimal implementation of OpenGL. but i left the app run for 20 minutes at 100 fps, hopefully the memory is all being released properly. i'm not sure why, but attempting to SetTimer faster than 100 fps when using OpenGL results in no change.

people aren't clear. i've written my own 3d engine, conceiving of the frustrum and drawing AA triangles with my own algorithm and SetPixel, i could get about 500 on XP, before i could figure out how i'm supposed to use OpenGL. the way other people write things doesn't always delight me, and i've always had immense difficulty understanding how to use any resources others offer. just show me htf to use OpenGL, i don't want glut or anything.

the reason for posting this source is because no tutorials simultaneously work with (1) a comprehending minimum of OpenGL requirements, and (2) a modern win32 default document.

microsoft have a tutorial document published in 2019 that isn't even unicode compliant. tutorial apps use triangles with three coordinates at .6 because you ought to know the history of werner von braun JPL, NASA, and so forth. if petzold wanted to teach windows instead of sell pages, that book would have been a quarter of the size. i get really angry at the pretense of egalitarianism at microsoft because the first girl i went steady with was a rainbow and i can see all your stuff. and i chainsaw things all day.
