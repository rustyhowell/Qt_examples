#!/usr/bin/env python


def getSha1():

    s = "this is a test"
    try:
        import hashlib
        hash = hashlib.sha1()
        hash.update(s)
        print "using hashlib"

    except:
        # Python 2.5
        import sha
        hash = sha.new("this is a test")
        #hash.hexdigest()
        print "using sha"

    return hash.hexdigest()




print getSha1()
