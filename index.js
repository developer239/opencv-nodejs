const addon = require('bindings')({
  bindings: 'opencv-nodejs',
  // TODO: figure out a better way to do this?
  try: [['module_root', 'cpp', 'build', 'Release', 'bindings']]
})

const test = async () => {
  console.log('addon.hello()', addon.hello)

  try {
    const result = await addon.hello('eee')
    console.log('result', result)
  } catch(e) {
    console.error(e)
  }
}

test()

module.exports = {
  Point2: addon.Point2,
  Size: addon.Size,
  Rect: addon.Rect,
  Vec2: addon.Vec2,
  Vec3: addon.Vec3,
  Vec4: addon.Vec4,
  RotatedRect: addon.RotatedRect,
}
