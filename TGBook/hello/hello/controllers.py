# -*- coding: utf-8 -*-
"""This module contains the controller classes of the application."""

# symbols which are imported by "from hello.controllers import *"
__all__ = ['Root']

# standard library imports
# import logging
import datetime

# third-party imports
from turbogears import controllers, expose, flash

# project specific imports
# from hello import model
# from hello import json


# log = logging.getLogger("hello.controllers")


class Root(controllers.RootController):
    """The root controller of the application."""

    @expose(template="hello.templates.welcome")
    def index(self):
        """"Show the welcome page."""
        # log.debug("Happy TurboGears Controller Responding For Duty")
        return dict(now=datetime.datetime.now())        

    @expose(template="hello.templates.hello")
    def hello(self):
        """"Show the welcome page."""
        # log.debug("Happy TurboGears Controller Responding For Duty")
        # return dict(now=datetime.datetime.now())    
        return dict(greeting="Greetings from the Controller")
