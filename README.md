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
2. For the standard program follow instructions 3-10, the complex formula follow instructions 11-20, for individual insulators follow instructions 21-30
3. Type "start" at the start
4. Enter the latent temperator throughout the rod in celcius (22 is average room temperator) (decimals are acceptable)
5. Enter the amount of sections you want in the rod (integer)
6. Enter the constant k value (preferably between 0 and 1)
7. Enter the amount of sinks and sources on your rod
8. Enter the locations and the temps at those locations
9. Answer yes to run a tick and see the output
10. Repeat step 9 until desired. Then type "no" to exit.
11. Type "complex" at the start
12. Enter the latent temperator throughout the rod in celcius (22 is average room temperator) (decimals are acceptable)
13. Enter the amount of sections you want in the rod (integer)
14. Enter the thermal conductivity of the rod (preferably between 0 and 1)
15. Enter the length of length of time between each tick.
16. Enter the distance between each section of the rod.
17. Enter the amount of sinks and sources on your rod
18. Enter the locations and the temps at those locations
19. Answer yes to run a tick and see the output
20. Repeat step 19 until desired. Then type "no" to exit.
21. Type "Insulator" at the start
22. Enter the latent temperator throughout the rod in celcius (22 is average room temperator) (decimals are acceptable)
23. Enter the amount of sections you want in the rod (integer)
24. Enter the constant k for each section of the rod.
25. Enter the amount of sinks and sources on your rod
26. Enter the locations and the temps at those locations
27. Answer yes to run a tick and see the output
28. Repeat step 27 until desired. Then type "no" to exit.


standard view:
+-----+-----+-----+-----+-----+
| 100 | 10  | 10  | 10  | 10  |
+-----+-----+-----+-----+-----+