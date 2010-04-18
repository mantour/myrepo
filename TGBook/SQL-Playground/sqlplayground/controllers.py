# -*- coding: utf-8 -*-
"""This module contains the controller classes of the application."""

# symbols which are imported by "from sqlplayground.controllers import *"
__all__ = ['Root']

# standard library imports
# import logging
import datetime

# third-party imports
from turbogears import controllers, expose, flash

# project specific imports
# from sqlplayground import model
# from sqlplayground import json


# log = logging.getLogger("sqlplayground.controllers")


class Root(controllers.RootController):
    """The root controller of the application."""

    @expose(template="sqlplayground.templates.welcome")
    def index(self):
        """"Show the welcome page."""
        # log.debug("Happy TurboGears Controller Responding For Duty")
        flash(_(u"Your application is now running"))
        return dict(now=datetime.datetime.now())
