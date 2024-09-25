# Sonara Writeup

### Running the Binary to See What It Looks Like in Execution
![Local Image](./Capture%20d'écran%202024-09-25%20203741.png) <br>
![Local Image](./Capture%20d'écran%202024-09-25%20203801.png)
The challenge seems to be taking our input, comparing it to the real flag, and returning the result of this comparison. From this perspective, reversing this binary will lead us to get the real flag!

### Getting Some Information About the Binary
![Local Image](./Capture%20d'écran%202024-09-25%20204953.png)
![Local Image](./Capture%20d'écran%202024-09-25%20205221.png)
The original code seems to be written in GoLang.

#### Disassembling with Ghidra
![Local Image](./Capture%20d'écran%202024-09-25%20210143.png)

Nothing seems to be helpful in this case, so it is time to try with IDA (the free edition).

#### Using IDA
![Local Image](./Capture%20d'écran%202024-09-25%20130126.png)
We are seeing some Go-defined functions with disassembling graphs helping us understand the code handling our input.

Let’s go deeper and statically analyze the assembly code:
![Local Image](./Capture%20d'écran%202024-09-25%20192947.png)
- The `main.welcome` function writes out the `Flag: ` string and then reads our input (with `fmt.Fscanln`).
- Then, the code starts injecting what seems to be the encrypted flag into the stack from `rsp+82` to `rsp+120`. The flag length seems to be 38 bytes.

#### Input Manipulation
![Local Image](./Capture%20d'écran%202024-09-25%20202350.png)
- The array containing our input is accessed and tested if `index % 2 = 1`.
- If so, we shift left by 1 the byte of our input indexed by this index. Otherwise, we multiply it by 2.

### Overview of the Assembly Graph
![Local Image](./Capture%20d'écran%202024-09-25%20203502.png)
This graph reflects the flow of the execution. The input is handled from the first to the last byte, getting encrypted, and then it is compared with the encrypted flag.

### Reverse Engineering the Process

Now that we know how our input is manipulated, we can reverse the process and pass the encrypted flag to it to get the real flag!

Here is the code for this operation:
![Local Image](./Capture%20d'écran%202024-09-25%20215847.png)


And this is the result:
![Local Image](./Capture%20d'écran%202024-09-25%20220007.png)
