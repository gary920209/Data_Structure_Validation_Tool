# Verification Tool README

This repository contains a simple verification tool to test your code against predefined test cases. Follow the steps below to use the tool and ensure your program is working as expected.

---

## Usage Instructions

1. **Replace `main.cpp`**  
   Replace the `main.cpp` file in this repository with your own implementation code.

2. **Run the tool**  
   Execute the following command in your terminal:
   ```
   bash run.sh
   ```

3. Check the results
If your program passes all the test cases, the output will display:
```All test cases passed```
If there are errors, the output will show:
```{number} test cases failed.``` 

4. Notes on Errors
Overflow Errors:
In the test cases provided, it is guaranteed that no integer overflow should occur when using the ```int``` type. However, the current version of this tool does not detect or handle overflow errors that may arise from incorrect implementations. If you encounter such errors, it is recommended to debug and adjust your implementation. Contributions to improve this aspect of the tool are welcome!

5. Contribution
If you want to contribute to enhancing this tool, such as by adding overflow detection, feel free to submit a pull request. Contributions to improve the tool and make it more robust are highly appreciated.

