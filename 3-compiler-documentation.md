Documentation
=============

In total the documentation burden is (at most) 1000 words
plus one diagram. Assesment of the documentation is not relative
to compiler functionality, it just requires a description
of the compiler as-is, and a realistic assessment of the
compiler's strengths and weaknesses.


AST
===

Overview Diagram
----------------

![my-ast.png](my-ast.png)

Description
-----------

My AST uses an abstract class structure and based one the C89/C90 grammar. The AST has a base class called "Program" that contains the virtual function for all subclasses, and on top of the base class there is a special class called "ALL" which carries the information of stack size, stack index and so on, that information could be access by all the class.

The stack is calculated before the code production phase of the compiler, a virtual function is been implemented to calculated how much stack needed in this particular c89 file, during run time the AST will run through the input file first to calculate how many stacks its needed and store back that information to a pre-defined variable, then in the Mips code production phase the AST could access this information and know how much stack it needs to reserve for this particular input file.

On the graph, you could see each statement have it own class associated with it, in expression statement, there is a sub-AST implemented when executing a longer assignment expression, for example, "x = y - 10 + z * x", assume that int x, y and z are predefined integers. The grammar defines which expression should be executed first, the equation will reduce to a smaller tree after each execution, and because of the limitations of register each calculated result will send back to the stack and push to the binding map to save register.

Strengths
---------

_Give two strengths or capabilites of your AST, using 50 words or less for each one_.

### Strength 1

My AST uses an abstract structure which the top-level class defines a common protocol for all class to simplify the complexity, and the top-level class inheritance from a class which defines all the variables, for example, the index of the stack, this is to avoid using global variables.

### Strength 2

The AST of my compiler have different print function for each individual case rather than one print function which use multiple if statements, the codepoint function is defined as virtual function in the top-level so the subclasses could override some certain behavior rather than implement one function in each class, each print function is called during different situation to avoid miss understanding.

Limitations
-----------

_Give two limitations of your AST, using 50 words or less for each one_.

### Limitation 1

The AST have a class sit on top of the base class to avoid using global variables, but for this method to be truly accessible for every class, a class pointer need to be declared in the main Cpp file and all the print function need to have that pointer specified before executing the function.

### Limitation 2

Using more than one print function during the code generation phase simplifies the complexity of one single print function, however, sometimes it leads to duplication of the same procedure in one function and more classes is needed to call the different printing functions in the different situation.  

Variable binding
================

General approach
----------------

In this particular compiler, $t0 is used to be the temporary register to store the result of arithmetic value, and $t1 is used to store the calculated value in expression statement.

Other registers like $t3 and $t4 are used when logical-and expression and logical-or expression is being calculated to avoid overwrite of registers, everything is being pushed to the stack. The size of the stack is calculated before the execution, and the frame pointer is not used in this specific API.

Two binding maps is used in this API, the first binding map is used to bind the variable name and its specified stack index, another binding map is used to bind the calculated number when doing multiple assignment expression or arithmetic expression, for example in "x = 10 * 10 - 9 * 9" the two multiplicative expression is calculated first and pushed to the stack with its own label, then the equation become " x = label1 - label2 " then the compiler pick the information from those labels according to the binding map and execute the next addictive expression.

when encountering a global variable the binding map will bind the id of the global variable and a specified flag, that same procedure to function declaration.

Strengths
---------

_Give two strengths or capabilites of your binding approach, using 50 words or less for each one_.

### Strength 1

The binding map of variable uses one binding to bind all declaration, that includes function declaration, global variable declaration, and local variable, global variable have a flag of "-2" and function declaration have a flag of "-3" so that expression know what type of information it is handling during execution.

### Strength 2

Another binding map of calculation is used to save registers, compare to stack we have very limited register and specifically temporary registers, when executing a more complex assignment expression the higher level priority expression will be calculated first and store back to stack, and the position of the stack is then stored in the binding map with its own label to avoid conflicts with the variable.

Limitations
-----------

_Give two limitations of your binding approach, using 50 words or less for each one_.

### Limitation 1

Because there is only one binding map for all three types of the declaration, there is a possibility the global variable could be rewritten if for example declare a global variable called "x" first then declare it again as a local variable.  

### Limitation 2

Implement a binding map just for calculation is good for complex calculation but it is slower than the method that uses registers only.

Reflection
==========

Strengths
---------

_What two aspects of your compiler do you think work well (beyond
those identified in the AST and binding parts)?_

### Strength 1

I think my compiler works really will with complex calculation since it uses a binding map just for arithmetic calculation, when the calculation is heavy enough that you have to push some of the information to the stack then my API start to show better preference compare to other compilers.

### Strength 2

My compiler also save registers really will since all the information have its own copy in the stack, when a large program that requires a lot of resources and registers, my compiler would still work since it only requires a few register to calculate complex expression.

Scope for Improvment
---------------------

### Improvement 1

I think the binding method of my compiler could be improved, now everything with the same name can only be declared once and only once, if define global variable "x" or function "x", there cannot be any local variable with the same name inside any scope. Thus it could really be improved by using a different method.

### Improvement 2

I also think the Mips code generation printing function could be improved, now I am using multiple print function to separates each case of declaration when it needed, but it needs to increase the class size and sometimes leads to duplications.

_50 words or fewer_


Functionality (not assessed)
============================

Which of these features does your compiler support (insert
an `x` to check a box):

1 - [x] Local variables
2 - [x] Integer arithmetic
3 - [x] While
4 - [x] IfElse
5 - [x] For
6 - [x] Function calls
7 - [ ] Arrays
8 - [ ] Pointers
9 - [ ] Strings
10 - [ ] Structures
11 - [ ] Floating-point

Note that all features will be tested, regardless of what
appears here. This is documentation of what you expect to work,
versus what doesn't work.


Feedback (not assessed)
=======================

_What aspects of your compiler would you like feedback on.
Be specific, as "what could I have done differently" is
too general to answer._

### Feedback 1

_20 words or fewer_

### Feedback 2

_20 words or fewer_
