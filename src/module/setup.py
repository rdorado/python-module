from setuptools import setup, find_packages
from distutils.extension import Extension

VERSION = '0.0.1' 
DESCRIPTION = 'Python package'
LONG_DESCRIPTION = 'Python package'

# Setting up the module
setup(
        name="module", 
        version=VERSION,
        author="Ruben Dorado",
        author_email="<ruben.dorados@gmail.com>",
        description=DESCRIPTION,
        long_description=LONG_DESCRIPTION,
        packages=find_packages(),
        install_requires=[],

        keywords=['python', 'first package'],
        classifiers= [
            "Development Status :: 3 - Alpha",
            "Intended Audience :: Education",
            "Programming Language :: Python :: 3",
        ],

        ext_modules=[
            Extension("module", ["module.cpp"])
        ]
)