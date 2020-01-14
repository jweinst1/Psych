from distutils.core import setup, Extension
import os
import sys

keyword_list = [
    'graphs',
    'graph',
    'data science',
    'big data',
    'ML'
]

classifers_list = [
    'Development Status :: 2 - Pre-Alpha',
    'Operating System :: MacOS',
    'Operating System :: Microsoft :: Windows',
    'Operating System :: Unix'
]

macro_defs = []

if os.name == 'nt':
  macro_defs.append(('_CRT_SECURE_NO_WARNINGS', '1'))

# For development or debugging purposes only, can be used by doing
# $ python setup.py build --mem-debug
if '--mem-debug' in sys.argv[1:]:
  macro_defs.append(('PSYCH_MEM_DEBUG', '1'))
  sys.argv.remove('--mem-debug')

# Version definition
macro_defs.append(('PSYCH_VERSION', '1'))
macro_defs.append(('PSYCH_MAJOR_VERSION', '0'))
macro_defs.append(('PSYCH_MINOR_VERSION', '0'))
macro_defs.append(('PSYCH_PATCH_VERSION', '3'))

# A Python package may have multiple extensions, but this
# template has one.
module1 = Extension('psych',
                    define_macros = macro_defs,
                    include_dirs = ['include'],
                    sources = ['src/demo.c'])



setup (name = 'psych',
       version = '0.0.1',
       description = 'Stock market modeling of the future.',
       author = 'Joshua Weinstein',
       author_email = 'jweinst1@berkeley.edu',
       url = 'https://github.com/jweinst1/Psych',
       long_description = open('README.md').read(),
       keywords = keyword_list,
       classifiers = classifers_list,
       ext_modules = [module1])