### 6.4 Algorithms 
(page 199)

The STL provides several standard algorithms for processing elements of collections. These algorithms
offer general fundamental services, such as searching, _sorting_, _copying_, _reordering_, _modifying_,
and _numeric processing_.

Algorithms are not member functions of the container classes but instead are global functions
that operate with iterators. This has an important advantage: Instead of each algorithm being implemented
for each container type, all are implemented only once for any container type. The algorithm
might even operate on elements of different container types. You can also use the algorithms for userdefined
container types. All in all, this concept reduces the amount of code and increases the power
and the flexibility of the library.

**Note** that this is **NOT** an **object-oriented programming paradigm**; it is a **generic functional programming
paradigm**. Instead of data and operations being unified, as in object-oriented programming,
they are separated into distinct parts that can interact via a certain interface. However, this
concept also has its price: 
* First, the usage is not intuitive. 
* Second, some combinations of data structures and algorithms might not work. 
* Even worse, a combination of a container type and an algorithm might be possible but not useful (for example, it may lead to bad performance).