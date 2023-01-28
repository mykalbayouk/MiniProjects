# BiomeGenerator
  This mini project of mine is to develop a bio generator using cellular automata. The current build of this allows the user to input the length of assets they want to use (will be built into a square matrix), then ask them the value of "noise density", noise density is basically how much or how little random assets do you want to be created when the inital noise map is generated, for this file I have it so noise values closer to 100 provide more '0' elements and, those values closer to 0 provide more ' ' elements. The last question asked to the user is how many iterations are to be run. Basically, the more iterations the more stuff equalizes into one extreme.  

# Future goals:
* Be able to use a hydration/elevation map in order to create a biome
* Use this sort of algorithm for planetary automation creation 
* Get visuals linked to the different assets 

# How to use

To run the file:
```
make run
```

To clean the workspace:

``` 
make clean
```
