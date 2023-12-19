# CoordinatePlane

CoordinatePlane is a simple library for creating a coordinate plane and performing basic geometric operations.

## Usage

1. **Coordinate Class**: Used to create a coordinate plane and perform operations on it.

    ```cpp
    Coordinate plane(15); // Default size is 15
    ```

2. **Point Class**: Used to create points on the coordinate plane.

    ```cpp
    Point p1(plane, "A", 2, 3); // Point 'A' at (2,3)
    Point p2(plane, "B", -1, 5); // Point 'B' at (-1,5)
    ```

3. **Line Class**: Used to create lines between two points.

    ```cpp
    Line AB("AB", p1, p2); // Line 'AB' between points A and B
    ```

4. **Info Function**: Used to display information about the lines.

    ```cpp
    AB.info({AB}); // Display information about line 'AB'
    ```

    The `info` function provides information about the lines, including distance, slope, and angle.

