/A X/ { p1 += 3+1; p2 += 0+3; }
/A Y/ { p1 += 6+2; p2 += 3+1; }
/A Z/ { p1 += 0+3; p2 += 6+2; }
/B X/ { p1 += 0+1; p2 += 0+1; }
/B Y/ { p1 += 3+2; p2 += 3+2; }
/B Z/ { p1 += 6+3; p2 += 6+3; }
/C X/ { p1 += 6+1; p2 += 0+2; }
/C Y/ { p1 += 0+2; p2 += 3+3; }
/C Z/ { p1 += 3+3; p2 += 6+1; }

END { print("02:", p1, p2) }
