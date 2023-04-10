# OpenGL-Win32-triangle

this is the msvc 2019 default win32 c++ app framework with comments removed, a timer added to call WM_PAINT for animation, and OpenGL instructions to clear the screen and draw a triangle with a moving point during WM_PAINT.

the only dependencies are:


#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>

#pragma comment(lib, "opengl32.lib")



i'm new to actually using OpenGL so i don't know if i'm imparting any poor methods because it's taken so long (15 years+) to determine an effective yet minimal implementation of OpenGL. but i left the app run for 20 minutes at 100 fps, hopefully the memory is all being released properly. i'm not sure why, but attempting to SetTimer faster than 100 fps when using OpenGL results in no change.

people aren't clear. i've written my own 3d engine, conceiving of the frustrum and drawing AA triangles with my own algorithm and SetPixel, i could get about 500 on XP, before i could figure out how i'm supposed to use OpenGL. the way other people write things doesn't always delight me, and i've always had immense difficulty understanding how to use any resources others offer. just show me htf to use OpenGL, i don't want glut or anything.

the reason for this is because no tutorials simultaneously work with (1) a comprehending minimum of OpenGL requirements, and (2) a modern win32 default document.

microsoft have a tutorial document published in 2019 that isn't even unicode compliant. you fix it microsoft, that's your job. the security of your compiler or OS isn't a valid reason to upend the language people use to make things happen in.

tutorial apps use triangles with three coordinates at .6 because you ought to know the history of werner von braun JPL, NASA, and so forth. if petzold wanted to teach windows instead of sell pages, that book would have been a quarter of the size. i get really angry at the pretense of egalitarianism at microsoft because the first girl i went steady with was a rainbow and i can see all your stuff it's obvious. and i chainsaw things all day.

i'm sorry there's no screenshot visible without clicking on it as a file, but github seem to want me to join a cult to use their site instead of facilitating use. in the old days, we "uploaded" and "downloaded" we didn't "push" and "pop". you may be alright with "push" and "pop" but when i spent two weeks working on the first project i had uploaded to github, it told me i couldn't upload the new version because there were new changes ot the old version online i needed to download or "pop" or whatever.

telling me you've go tth enew version of a project i just spent 2 weeks writing isn't good or cool. it coudl ge tyou brutalised. jsut provide a platform, i don't want to have to dress up funny or talk funny or copulate with anything abnormal to use github. in order to add an image to the page, you have ot use fing css and make three directories. that's not facile dudes. the sourc ei'm sharing is ONE document. adding eighteen documents to display an image isn't helping.

"The Least You Need to Know About GitHub Pages"
https://tomcam.github.io/least-github-pages/

sweet jesus understand the least you need to know is ALWAYS the most you need to know. C is elegant. you ms github keep your filthy little hands offa it.
