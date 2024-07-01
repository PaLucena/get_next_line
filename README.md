
<h1 align="center">get_next_line</h1>

<h2>Description</h2>
<p><strong>get_next_line</strong> is a project from the 42 cursus that involves creating a function to read a line from a file descriptor. The main objective is to handle and manage file input efficiently, understand buffer management, and handle edge cases such as reading from a file, stdin, or even network connections.</p>

<h2>Table of Contents</h2>
<ul>
	<li><a href="#requirements">Requirements</a></li>
	<li><a href="#installation">Installation</a></li>
	<li><a href="#usage">Usage</a></li>
	<li><a href="#project-structure">Project Structure</a></li>
	<li><a href="#license">License</a></li>
</ul>

<h2 id="requirements">Requirements</h2>
<p>To compile and run the project, you will need:</p>
<ul>
	<li>A Unix operating system (Linux or macOS).</li>
	<li>gcc or any C compiler.</li>
	<li>Make.</li>
</ul>

<h2 id="installation">Installation</h2>
<p>Clone the project repository and navigate to the main directory:</p>
<pre><code>git clone https://github.com/PaLucena/get_next_line.git
cd get_next_line</code></pre>
<p>Compile the project using the next command:</p>
<pre><code>gcc get_next_line.c get_next_line_utils.c your_project.c</code></pre>

<h2 id="usage">Usage</h2>
<p>To use the <code>get_next_line</code> function in your own project, include the <code>get_next_line</code> files in your project and the corresponding header file:</p>
<pre><code>#include "get_next_line.h"</code></pre>
<p>The <code>get_next_line</code> function prototype is:</p>
<pre><code>char *get_next_line(int fd);</code></pre>
<p>Example usage in a program:</p>
<pre><code>
#include "get_next_line.h"
#include fcntl.h
#include stdio.h

int main() {
	int fd = open("test.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}
</code></pre>

<h2 id="project-structure">Project Structure</h2>
<p>The project is organized into the following files and directories:</p>
<ul>
	<li><code>src/</code>: Contains the source code of the <code>get_next_line</code> implementation.</li>
	<li><code>include/</code>: Contains the header files.</li>
	<li><code>Makefile</code>: Build script to generate the library.</li>
	<li><code>README.md</code>: Project documentation.</li>
</ul>

<h2 id="license">License</h2>
<p>This project is licensed under the MIT License. See the <code>LICENSE</code> file for more details.</p>
