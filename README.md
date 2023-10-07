# Sijmen J. Mulder's advent of code visulaizations

I was impressed with sjmulder's https://sjmulder.nl/2022/aoc-ffmpeg.html idea to pipe raw frames to ffmpeg for visualisation.

I have modified his aoc solutions (days 14,18,20,22,23,24) to pipe to stdout. This allows the same code to be rendered to the screen in real time using https://github.com/tom-huntington/display-frames when you are debugging. And to a mp4 file when you are finished. Just change the shell commands!

Instant debugging
```
./dayXX | displayframes --size {width}x{height}
```

Easy render
```
./dayXX | ffmpeg -loglevel warning -stats -f rawvideo -pixel_format rgb24 -video_size {width}x{height} -framerate 30 -i - -pix_fmt yuv420p dayXX.mp4
```

More in details 2022/c/README.md
