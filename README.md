# Go-With-the-Flow
    Background
Write a class called HeatFlow which will simulate the one-dimensional flow of heat in a thin rod. A user should be able to specify different parameters of the simulation including the initial temperature of the rod, the length of the rod, the constant K, and any number of sources / sinks.

        Getting Started
    Prerequisites
Are there any prerequisites for your project? If so, list them here. If note, you can delete this section.

    1. C++ v14
    2. Visual Studio

    Set Up
1. Copy the repository.
2. Load Code in Visual Studio.
3. Press Run button(or F5).
    
    Running the Test Suite
1. Start the code
2. Type "test" when starting instead of typing in "start"
3. Test should run through automatically, check output to verify that the outputs are correct.
4. if you want to update or change test go into tester method in main.cpp and if you want to add additional presets you can add them in the heatsink contractor.

    Running code
1. Start the code
2. Type "start" at the start
3. Enter the latent temperator throughout the rod in celcius (22 is average room temperator) (decimals are acceptable)
4. Enter the amount of sections you want in the rod (integer)
5. Enter the constant k value (preferably between 0 and 1)
6. Enter the amount of sinks and sources on your rod
7. Enter the locations and the temps at those locations
8. Answer yes to run a tick and see the output
9. Repeat step 8 until desired. Then type "no" to exit.

standard view:
+-----+-----+-----+-----+-----+
| 100 | 10  | 10  | 10  | 10  |
+-----+-----+-----+-----+-----+