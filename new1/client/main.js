 import { Template } from 'meteor/templating';
import { ReactiveVar } from 'meteor/reactive-var';
import { Mongo } from 'meteor/mongo';
import { Accounts } from 'meteor/accounts-base';
import { Meteor } from 'meteor/meteor';
import { check } from 'meteor/check';

Accounts.ui.config({
  passwordSignupFields: 'USERNAME_ONLY',
});

import './main.html';

 Ashu1 = new Mongo.Collection('ashu');
Template.hello.onCreated(function helloOnCreated() {
  // counter starts at 0
  this.counter = new ReactiveVar(0);

});

/*Templete.new.helpers({
	ashu: function(){
  	return Ashu1.find();
  },
});*/

Template.hello.helpers({
  counter() {
    return Template.instance().counter.get();
  },
  task: function() {
    console.log("godara sikar rajasthan");
    return "ashutosh";
  },
  tasks: function() {
    return Ashu1.find({},{sort:{ createdAt: -1}});//.count();
  },
});

Meteor.methods({
  'ashu.insert'(text,number) {
    check(text, String);
    check(number, Number);

    if (! this.userId) {
      throw new Meteor.Error('not-authorized');
    }
 
    Ashu1.insert({
      text,
      createdAt: new Date(),
      owner: this.userId,
      username: Meteor.users.findOne(this.userId).username,
    });
  },
});
Template.hello.events({
  'click .click_me'(event, instance) {
    // increment the counter when button is clicked
    instance.counter.set(instance.counter.get() + 1);
    console.log(event.type);
  },
  'submit .cont'(event) {
    console.log("my console log clicked");
    console.log(event.type);
    event.preventDefault();
    var target = event.target;
    var text = target.text.value;
    var score = target.number.value;
    /*event.preventDefault();

    Ashu1.insert({
      text: "ashutosh godara",
      createdAt: new Date(),
    });*/
    Ashu1.insert({
      text,
      createdAt: new Date(),
      score,
      owner: Meteor.userId(),
      username: Meteor.user().username,
    })

    target.text.value = '';
    target.number.value = '';
    console.log("new field inserted");
  },
  'click .player': function() {
    var playerId = this._id;
    Session.set('selectedPlayer',playerId);
  },
  'click li': function() {
    
     var selectedPlayer = Session.get('selectedPlayer');
    console.log(selectedPlayer);
  },
  'click .del': function() {
    var selectedPlayer = Session.get('selectedPlayer');
    return Ashu1.remove({_id : selectedPlayer});
  },
  'click .update' : function() {
    var selectedPlayer = Session.get('selectecPlayer');
    return Ashu1.update(selectedPlayer, { $set: {text: "Arjun"}});
  },
  'click .toggle-checked'() {
    // Set the checked property to the opposite of its current value
    Ashu1.update(this._id, {
      $set: { checked: ! this.checked },
    });
  },
  'click .delete'() {
    Ashu1.remove(this._id);
  },
});
