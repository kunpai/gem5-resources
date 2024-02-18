# make.def files for the NPB benchmarks

This directory contains the make.def files for the NPB benchmarks for different ISAs.  These files
are used to specify the compiler and compiler flags for the benchmarks.  The
make.def files are used by the NPB makefiles to build the benchmarks.

The make.def files are named according to the following convention:

```
make_<ISA>.def
```

where `<ISA>` is the name of the ISA for which the make.def file is intended.  For example, the make.def file for the x86 ISA is named `make_x86.def`.

Please note that the `make_x86.def` file and the `make_ARM.def` file assume that you are running on a native system.  If you are cross-compiling, you will need to modify these files to specify the correct compiler and compiler flags for your target system.