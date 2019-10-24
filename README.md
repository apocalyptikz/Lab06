<h4 id="data-structures">Data Structures</h4>
<h1 id="lab-6">Lab 6</h1>
<ul>
<li>This assignment tests the concepts of:
<ul>
<li>Stacks</li>
<li>Templates</li>
</ul></li>
</ul>
<h2 id="objective">Objective</h2>
<ul>
<li>You will write a program that acts as a simple postfix calculator, reading a file (filename provided as argument) that contains an arithmetic expression on each line. The program evaluates these expressions and prints the values to cout. The expressions are postfix expressions (as described on page 331 of the text).</li>
<li>All your work should be concentrated on the process_line function. Implement the function is a seperate file named “processline.cpp” with your implementation.</li>
<li>However, the calculator depends on the Stack class, which is expected to be templated.</li>
</ul>
<h3 id="part-1">Part 1</h3>
<ul>
<li>A non-Templated mystack class is provided. Modify the stack class to be a templated class that will work for any node type. All code for the class should be in myclass.h (instead of the current two).</li>
<li>Add additional text cases to the provided test file. Your code should work for ALL possibilities.</li>
</ul>
<h3 id="part-2">Part 2</h3>
<ul>
<li>Implement processline</li>
</ul>
<h3 id="alternate-order">Alternate order</h3>
<ul>
<li>You may choose to change the typedef to double inside mystack.h and work on getting the calculator to work, After getting the calculator to work, going back and templating mystack.</li>
</ul>
<h2 id="additional-criteria">Additional Criteria</h2>
<ol type="1">
<li>Memory leaks will lead to grade leaks on this assignment. No heap memory should be in use when the main function reaches the return 0.</li>
<li>Absolutely no #includes other than iostream (for istream, &gt;&gt;, peek, and ignore), cmath (for std::nan(“Invalid”);), limits (for std::numeric_limits<std::streamsize>::max()), cstring (for strchr), and cctype (for isdigit)</li>
<li>No recursion!</li>
</ol>
<h2 id="example-output">Example Output</h2>
<pre><code>12
34
nan
12

done</code></pre>
