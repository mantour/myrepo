from turbogears import testutil
from bookmark.controllers import Root
import cherrypy

def test_list_controller():
    """list method should return a set of bookmark objects called bookmark."""
    cherrypy.root = Root()
    output=testutil.call(cherrypy.root.list)
    assert output.has_key('bookmark')
