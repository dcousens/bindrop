# bindrop
A streaming binary `cut` tool,  pipes `stdin` to `stdout`.

Byte-for-byte, **not UTF8 aware**.

## Examples
Drop bytes 4:8, every 17 bytes
``` bash
> echo -e 'whats in the box\nwho has the box?' | ./bindrop 4 8 17
what the box
who the box?
```
**Warning**: if the bytes read is not a multiple of the slice length (for example, 17 bytes), the remainder is truncated (dropped).

## LICENSE [MIT](LICENSE)
