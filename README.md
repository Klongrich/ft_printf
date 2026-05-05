# ft_printf — Custom `printf` Implementation

This project is a full custom re‑implementation of the standard C `printf` function.  
It supports **flags**, **width**, **precision**, **length modifiers**, and a wide range of **format specifiers**, including integers, hex, octal, pointers, floats, and even custom 8‑bit/16‑bit conversions.

Your implementation manually handles formatting logic, number conversion, padding, and printing — without relying on the standard library’s formatting functions.

---

## ✨ Features

### Supported Conversions
Your implementation supports:

- **Characters**: `%c`
- **Strings**: `%s`
- **Signed integers**: `%d`, `%i`
- **Unsigned integers**: `%u`
- **Hexadecimal**: `%x`, `%X`
- **Octal**: `%o`
- **Pointers**: `%p`
- **Floats**: `%f`, `%lf`, `%Lf`
- **Length modifiers**:
  - `hh` → 8‑bit conversions (`put_8bit_data`)
  - `h` → 16‑bit conversions (`put_16bit_data`)
  - `l` → 64‑bit conversions (`put_64bit_data_l`)
  - `ll` → 64‑bit conversions (`put_64bit_data_ll`)
  - `L` → long double floats

> Example from the document:  
> “`if (str[i] == 's') count += put_string_args(va_arg(list, char*), flags);`” 

---

## 🧩 Flag Support

Your implementation handles all major printf flags:

| Flag | Meaning |
|------|---------|
| `-` | Left‑justify output |
| `0` | Zero‑padding |
| `+` | Force sign on positive numbers |
| ` ` | Space before positive numbers |
| `#` | Alternate form (`0x`, `0`, etc.) |
| `.` | Precision control |

Flags are parsed in `parse_flags()` and stored in a `t_flags` struct initialized by `init()`.

> Example from the document:  
> “`flags.zero = 0; flags.left = 0; flags.padding = 0; ...`” 

---

## 🔢 Number Conversion System

Your implementation includes a full suite of custom number‑printing functions:

### Decimal / Hex / Octal
- `put_number()`
- `put_number_ll()`
- `put_number_ull()`
- `ft_numlen_hex()`
- `ft_numlen_oct()`

### 8‑bit and 16‑bit Conversions
Implemented **bit‑level extraction**, converting raw bits into octal or hex digits manually.

> Example:  
> “`bits[j++] = (num >> i--) & 1;`” 

These are used for:
- `%hhx`, `%hhX`, `%hho`, `%hhu`, `%hhd`
- `%hx`, `%hX`, `%ho`, `%hu`, `%hd`

### Pointer Printing
Pointers are printed with `"0x"` prefix and manual hex conversion:

> “`count += ft_count_putstr("0x"); count += putunit_max(address, 16);`” 

---

## 🧮 Float Handling

Floats are printed using:
- `put_float()`
- `put_float_value()`
- `print_float_decimal()`

Precision defaults to **6**, unless overridden by a precision flag.

> “`if (flags.dot) precision = flags.padding; else precision = 6;`” 

---

## 📦 Padding & Alignment Engine

Your implementation includes a robust padding system:

- `put_padding_zero()`
- `put_padding_right()`
- `put_padding_left()`
- `put_padding_zero_float()`
- `put_padding_left_float()`

Padding logic respects:
- left/right alignment
- zero padding
- precision
- sign handling
- alternate form (`#`)

> Example:  
> “`while (i < flags.padding - num_len) count += ft_putchar(' ');`” 

---

## 🧠 Core Engine: `ft_printf`

The main loop:

1. Iterates through the format string  
2. Detects `%` sequences  
3. Parses flags, width, precision  
4. Detects length modifiers  
5. Dispatches to the correct handler  
6. Prints the formatted output

> “`while (str[i] != '%' && str[i]) count += ft_putchar(str[i++]);`” 

---

## 📁 File Structure (based on the uploaded file)

```
ft_printf.c
ft_printf.h
[helpers for hex, octal, float, padding, bit conversion]
```

The uploaded file contains **all formatting logic**, including:

- flag parsing  
- number conversion  
- bit extraction  
- padding  
- float printing  
- dispatch logic  

---

## 🧪 Example Usage

```c
ft_printf("Value: %08x\n", 255);
ft_printf("Char: %-5c End\n", 'A');
ft_printf("Float: %.3f\n", 3.14159);
ft_printf("Pointer: %p\n", ptr);
ft_printf("8-bit hex: %hhX\n", 0xAB);
```

---
