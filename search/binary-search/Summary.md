# Summary

1. if you may find the exact data, you should use ```l < h```, else use ```l <= h```
   1. For ```l <= h```, When the find data is less than xxx, h = mid -1 and use h
   2. For ```l <= h```, When the find data is more than xxx, use l, but need to check the boundary
2. you could drop the middle for easy calculation
3. when mid is left```(mid = l + (h - l)/2)``` then usually h = mid to ensure, not miss the data. else versa.
4.