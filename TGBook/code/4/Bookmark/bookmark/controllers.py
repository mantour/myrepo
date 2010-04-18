# -*- coding: utf-8 -*-
"""This module contains the controller classes of the application."""

# symbols which are imported by "from bookmark.controllers import *"
__all__ = ['Root']

# standard library imports
# import logging
import datetime

# third-party imports
from turbogears import controllers, expose, flash, redirect

# project specific imports
# from bookmark import model
# from bookmark import json
from model import Bookmark

# log = logging.getLogger("bookmark.controllers")


class Root(controllers.RootController):
    """The root controller of the application."""

    @expose(template="bookmark.templates.welcome")
    def index(self):
        """"Show the welcome page."""
        # log.debug("Happy TurboGears Controller Responding For Duty")
        flash(_(u"Your application is now running"))
        return dict(now=datetime.datetime.now())
    @expose(template="bookmark.templates.list")
    def list(self):
        # from model import Bookmark
        b=Bookmark.select()
        return dict(bookmark=b,now=datetime.datetime.now())
    @expose()
    def save_bookmark(self,name,link,description):
        b=Bookmark(name=name,link=link,description=description)
        raise redirect("/list")
    @expose(template="bookmark.templates.form")
    def bookmark(self):
        return dict(now=datetime.datetime.now())
