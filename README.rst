Contiki cc2538 Emul8 example
============================

This repository shows a simple example of how to run `Contiki <https://github.com/contiki-os/contiki>`_ binaries in `Emul8 <http://emul8.org>`_, the open source emulator framework.

This example uses the Cortex-M based `cc2538 <http://www.ti.com/product/cc2538>`_ platform from Texas Instruments.

Repository contents
-------------------

* ``Makefile`` - a simple Contiki-style Makefile
* ``hello.c`` - an example program, which can be freely modified
* ``hello-cc2538.emul8`` - and Emul8 script which uses several features of the Emul8 scripting language, such as variables and macros.

Compiling
---------

To compile the Contiki binary, just run::

   make

Remember that you need an ARM compiler (you can use e.g. the ``gcc-arm-none-eabi`` Ubuntu package) in your PATH.

Running
-------

The Emul8 framework is required to be installed on your system.
This can be done running::

    ./build.sh -i

from the Emul8 directory.

To run the example, you can use::

    make emul8

which essentially calls Emul8 with the appropriate emulation script (you can do it by hand as well - just do ``emul8 <script-file>``).

The script will start the emulation automatically, and the provided binary should output some messages periodically to the UART analyser.

If you do not want the program to start automatically, just remove the ``s`` command (shorthand for ``start``) from the final line of the emulation script.

For more information, head to the `Emul8 documentation <http://emul8.readthedocs.org/en/latest/>`_.
