# How to contribute to DOOM for the numworks calculator

Thank you so much for wanting to help contribute to this project!!

This document is a set of guidelines for you to contribute to the DOOM game for the numworks calculator. These are more so guidelines than rules, but please keep them in mind.

# FAQ

[How should I set my enviroment up?](#how-to-setup-the-enviroment)

[How do I test my code?](#testing)

# Table of Contents

[Code of Conduct](#table-of-contents)

[Testing](#testing)

[Enviroment setup](#how-to-setup-the-enviroment)

[Naming convention](#naming-convention)
* [Branches](#branches)
* [Commits](#commits)
* [Functions](#functions)

[Styling guide](#style-guide)
* [Most things](#loops-ifs-classes-and-namespaces)
* [Functions](#functions-1)
* [Indentation](#indentation)

# Code of Conduct

This project and everyone assiciated is governed by the [Code of Conduct](https://github.com/riley0122/numworks_doom/blob/main/docs/CODE_OF_CONDUCT.md). When contributing, you are required to follow this code.

# Resources

* Bugs: [Github Issues](https://github.com/riley0122/numworks_doom/issues)

# Testing

You can test the project by running the [Tests workflow](https://github.com/riley0122/numworks_doom/actions/workflows/test.yml). This workflow will be automatically triggered when pushing to main, and is a requirement to push.

Tests are written with the [utest](https://github.com/sheredom/utest.h) testing framework. Tests are written in the `src/main.cpp` file, test are written in the bottom after the `#else` statement. This statement is the else to an if (`#ifndef TEST`) at the start of the file. This is because when compiling the project to run, this section will never be needed. If we compile to test we compile with the `-DTEST` flag, defining `TEST` and thus running the code after `#else`.

# How to setup the enviroment

The requirements to work on this project are:

* A (preferably debian based) linux distribution, this can also be WSL (Windows Subsystem for Linux)
* A working installation of Node.js
* A working installation of make
* A working installation of the [embedded ARM toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain). <br /> On debian based systems it can be installed with `#
apt install gcc-arm-none-eabi`.

You need to have those tools installed to compile this project.

### Compilation

In order to compile the project for the calculator, you can use `$ make build` or simply `$ make`.
This will output the `DOOM.bin` and `DOOM.nwa` (the important one) to the `target` folder.

To run the project on a numworks calculator, you can instead run `$ make run`. This will automatically upload the `DOOM.nwa` to your calculator if it is connected. If you have already built the project, you can upload the `target/DOOM.nwa` file to your calculator via the [numworks website](https://my.numworks.com/apps).

If you do not have access to a numworks calculator, fear not! This project can be built and ran on your local machine by going into the `test` folder (`$ cd test`) and running the `buildlocal.sh` file (`test$ ./buildlocal.sh`). The program will ask if you want to enable graphics or not, enter y/n if you want graphics or not.

#### ⚠️ As of writing this, graphics for local builds have not yet been implemented.  ⚠️

If you want to help adding graphics for local builds, please note we are planning to use the SDL2 library. Graphics are handled in the `src/eadk.cpp` file.

# Naming convention

This convention is based of [this article](https://dev.to/varbsan/a-simplified-convention-for-naming-branches-and-commits-in-git-il4). Please note however we have made some changes.

## Branches

### Category

A branch name should start with the category your changes fall in. You can choose from the following:

* `feature` is for adding, refactoring or removing a feature.
* `bugfix` is for fixing a bug.
* `test` is for trying things out. (`test` branches may never be merged into main)
* `refactor` is for when making any non-functional changes to the code.

### Reference

After the category, there should be a refrence to a ticket or pull request. The reference is the id of what you're referencing and the first 2 words of description in [kebab case](https://www.theserverside.com/definition/Kebab-case). If you are not referencing any specific issue or pull request use `no-ref`.

The reference comes after the category and is seperated by a "/".

### Description

After the reference, there should be a short description of what you are doing/changing. the description should be anywhere between 2 to 5 words. The description should be in [kebab case](https://www.theserverside.com/definition/Kebab-case) aswell.

The description comes after the reference and is seperated by a "/".

Branch description must be [the non finite verb phrase](#what-the-hell-is-the-non-finite-verb-phrase) of the [present continuous](https://learnenglish.britishcouncil.org/grammar/english-grammar-reference/present-continuous)

#### What the hell is the non finite verb phrase??

The non-finite verb phrase is a form of a [verb phrase](https://en.wikipedia.org/wiki/Verb_phrase). A verb phrase is basically the sentance without the subject, for example:
In the sentance "John has finished the work" one verb phrase is "has finished the work". However this still contains a [finite verb](https://en.wikipedia.org/wiki/Finite_verb), namely "has". One of the non-finite verb phrases in this scentance is "finished the work" because it doesnt contain any finite verbs. The only verbs are [non-finite](https://en.wikipedia.org/wiki/Nonfinite_verb).

### tl;dr
This is what you need to follow:
`$ git branch <category/reference/short-description>`

### Examples

1. You are adding tests for uncovered code: `$ git branch feature/no-ref/adding-missing-tests`
2. You are fixing a bug that was described in an issue: `$ git branch bugfix/#14-rotation-locking/fixing-rotation-snapping`
3. You have decided that some code looks messy and want to clean it up `$ git branch refactor/no-ref/cleaning-up-messy-code`

## Commits

### Types

Your commit must always start with what type of commit it is. You can choose from the following:
* `FEAT` is for when you are working something and you make a commit for a part you finished.
* `FIX` is for bugfixes, but also for adding small things you forgot, spelling errors, etc.
* `CHORE` is for the things you would skip if you could, things like writing this document for example.

### Description

After the type of commit you made, you write a short description of what you did. This is again 2 to 5 words. If you made multiple changes that fall under the same type, you can write 2 (or more) descriptions seperated by a ";".

Commit descriptions must be descriptive of what you did. Commit descriptions must be in the [Past simple](https://learnenglish.britishcouncil.org/grammar/english-grammar-reference/past-simple)

### Exceptions

Your commit may have a diffrent name if it is a merge commit. In that case it may have the default merging name. For example: `Merge pull request #26 from riley0122/feature/no-ref/modelGenerator-tool`. Merge commits must have a description stating what changed or what you did if that wasnt clear from the branch name.

### tl;dr
Your commit should look something like this:
`$ git commit -m '<TYPE: did something; did something else>'`.

Unless it's a merge commit, then the default name is fine.

### Examples

1. You added documentation to undocumented functions: `$ git commit -m 'CHORE: added comments to functionName in file.cpp'`
2. You added functions that handle 3D rotation: `$ git commit -m 'FEAT: added rotateZ; added roatateY; added rotateX'`

## Functions, Classes, etc.

Functions, Classes, namespaces, etc. are named in camelCase and must be at least slightly descriptive of what it does/contains. 

We prefer to use the single responsibility principle, this means that one function does one thing. This is not a requirement more so a preference.

### Examples

```cpp
// Rotates a point on the X axis
void rotateX(position point, float angle){
    position p;
    // The rotation maths based on the rotation matrix
    // (it is in src/renderer.cpp)
    return p;
}
```


```cpp
// Project a single point
position2D project(position point, Camera target){
    // perspective projection maths
    return {projectedX, projectedY};
}
```

# Style guide

A simple style guide how things like brackets should be formatted.

## Loops, Ifs, Classes, and Namespaces 

These things should have the brackets open on a new line.

i.e.

```cpp
namespace something
{
    // things
}
```

if statements and similar things should also be seperated from their condition with a space.

i.e.

```cpp
if (condition)
{
    // something
}
```

## Functions

Functions should have brackets inline of the function

i.e.

```cpp
void doSomething() {
    // Do whatever
}
```

If functions have a return type, they must always have a return statment at the bottom. Even if the function can never get to that point.

i.e.

```cpp
position getCenter(std::bool nonZero){
    if(!nonZero)
    {
        return {0, 0, 0};
    } else
    {
        return {1, 1, 1};
    }

    // Function can never get here
    return {0, 0, 0};
}
```

## Indentation

We use a tab space of 4 space characters.
