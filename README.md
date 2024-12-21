# L33T-converter-C-interfacing-ASM
This program is a Leet (L33T) speak converter using C language calling assembly language.

**Parameter Passing** for reference
| **parameter** | **long long int** | **int** | **short** | **char** | **float** |
|---------------|-------------------|---------|-----------|----------|-----------|
| 1st           | RCX               | ECX     | CX        | CL       | xmm0      |
| 2nd           | RDX               | EDX     | DX        | DL       | xmm1      |
| 3rd           | R8                | R8D     | R8W       | R8B      | xmm2      |
| 4th           | R9                | R9D     | R9W       | R9B      | xmm3      |
| Return        | RAX               | EAX     | AX        | AL       | xmm0      |

**for this program, RCX is used as a pointer to the input string. Dereferenced via [RCX]

## Sample Output
![image](https://github.com/user-attachments/assets/11339185-7093-49e7-8ec6-68c5d5736480)
