# get binary

```
wget https://github.com/tom-huntington/display-frames/releases/latest/download/displayframes
```

# Day 12
build:
```
gcc -O3 -Wall -Wextra vis.c day12-vis.c -o day12-vis
```


realtime display:
```
./day12-vis < ../../inputs/d12.in | ./displayframes --size 3148x904
```

encode file
```
./day12-vis < ../../inputs/d12.in | ffmpeg -loglevel warning -stats -f rawvideo -pixel_format rgb24 -video_size 3148x904 -framerate 30 -i - -pix_fmt yuv420p day12-vis.mp4
```

# Day 14

build
```
gcc -O3 -Wall -Wextra -DWITH_VIS=1 -o day14-vis day14.c vis.c
```

realtime display:
```
./day14-vis < ../../inputs/d14.in | ./displayframes --size 1024x336
```

```
./day14-vis < ../../inputs/d14.in | ffmpeg -loglevel warning -stats -f rawvideo -pixel_format rgb24 -video_size 1024x336 -framerate 30 -i - -pix_fmt yuv420p day14-vis.mp4
```

The rest of the commands for days `18, 20, 22, 23, 24` are the same but for the size and the day number:

# Get the size

```
$ ./day18-vis < ../../inputs/d18.in >/dev/null
size: 568 x 568
```