const testAddon = require('./build/Release/testaddon.node');

console.log('addon', testAddon);
console.log('hello', testAddon.hello());
console.log('add', testAddon.add(9, 5));

const classInstance = new testAddon.ClassExample(4.3);
console.log('Testing class initial value : ', classInstance.getValue());
console.log('After adding 3.3 : ', classInstance.add(3.3));

const newFromExisting = new testAddon.ClassExample(classInstance);
console.log('Testing class initial value from derived instance: ', newFromExisting.getValue());

module.exports = testAddon;
