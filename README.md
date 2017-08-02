# bindrop

[![build status](https://secure.travis-ci.org/dcousens/bindrop.png)](http://travis-ci.org/dcousens/bindrop)
[![Version](https://img.shields.io/npm/v/bindrop.svg)](https://www.npmjs.org/package/bindrop)

A streaming binary `cut` tool,  pipes `stdin` to `stdout`.

Byte-for-byte, simple, **not UTF8 aware** (thankfully).


## Examples

``` bash
// drop bytes 4:8, in 16 byte chunks
echo "whats in the box" | ./bindrop 4 8 16
> what the box
```
