from turbogears import database, testutil
from bookmark.model import Bookmark
from bookmark.controllers import Root
import cherrypy

database.set_db_uri("sqlite:///:memory:")

class test_full_stack(testutil.DBTest):
    def get_model(self):
        return Bookmark
    def test_list_template(self):
        """Checks to see that our template is applied"""
        cherrypy.root=Root()
        testutil.createRequest("/list")
        assert '<title>Bookmarker</title>' in cherrypy.response.body[0]
    def test_list_contents(self):
        """If we add a record to the model, it should
           show up in the final page text"""
        cherrypy.root=Root()
        Bookmark(name='Compound Thinking',
                link='http://www.CompoundThinking.com',
                description="A {not so} random link.")
        testutil.createRequest("/list")
        assert '<a href="http://www.CompoundThinking.com">' in cherrypy.response.body[0]
