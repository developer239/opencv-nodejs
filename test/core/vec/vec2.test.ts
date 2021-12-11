import { Vec2 } from '../../../index'

describe('[core] Vec2', () => {
  describe('constructor', () => {
    it('initializes from numbers', () => {
      const vec = new Vec2(4, 3)

      expect(vec.x).toStrictEqual(4)
      expect(vec.y).toStrictEqual(3)
    })

    it('should update instance properties', () => {
      const vec = new Vec2(4, 3)

      vec.x = 88
      vec.y = 77

      expect(vec.x).toStrictEqual(88)
      expect(vec.y).toStrictEqual(77)
    })
  })
})
