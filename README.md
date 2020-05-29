# dyld-tools

Experiment to attempt to build Apple's dyld tools. Based on dyld-733.6.

# Why?

I found myself wanting to create miniature `dyld_shared_cache` files for
unit testing purposes, where Apple's caches are both too large and obviously
not redistributable.

# Changes made

Vanilla upstream except for the `#ifdef HAVE_*` regions that disable features
relying on headers that aren't publicly available (as far as I know). The `ext/`
subdirectory contains various headers cherry-picked from Apple OSS components,
and a few hacky private header replacements written by me.

Only part known to be severely broken is `HAVE_METABOM`, though restoring this
shouldn't be hard, but may turn out to not be all that useful anyway. (As it
might be desirable to simplify the dyld_shared_cache_builder tool.)

# Prerequisites

- macOS system w/ Xcode
- Meson (pip3 install meson)
- Ninja (brew install ninja)

# Building

```sh
$ meson build
$ ninja -C build
$ ninja -C build install
```
